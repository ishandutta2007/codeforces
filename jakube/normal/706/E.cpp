#include <bits/stdc++.h>
using namespace std;

struct LL2D {
    LL2D* above = nullptr;
    LL2D* left = nullptr;
    LL2D* under = nullptr;
    LL2D* right = nullptr;
    int val;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >>  n >> m >> q;
    
    // create linked matrix
    vector<vector<LL2D*>> v(n + 2, vector<LL2D*>(m + 2, nullptr));
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            v[i][j] = new LL2D;
        }
    }

    // initialize and link
    LL2D* root = v[0][0];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (i) 
                v[i][j]->above = v[i-1][j];
            if (j)
                v[i][j]->left = v[i][j-1];
            if (i < n + 1) 
                v[i][j]->under = v[i+1][j];
            if (j < m + 1)
                v[i][j]->right = v[i][j+1];
            if (i && i < n + 1 && j && j < m + 1)
                cin >> v[i][j]->val;
        }
    }

    auto print = [root, n, m](){
        LL2D* current_row = root;
        for (int i = 0; i < n; i++) {
            current_row = current_row->under;
            LL2D* current = current_row->right;
            for (int j = 0; j < m; j++) {
                cout << current->val << ' ';
                current = current->right;
            }
            cout << '\n';
        }
    };

    // handle queries
    for (int idx = 0; idx < q; idx++) {
        int a, b, c, d, h, w;
        cin >> a >> b >> c >> d >> h >> w;

        // find left upper pixel of both rectangles
        LL2D* cur1 = root;
        for (int i = 0; i < a; i++)
            cur1 = cur1->under;
        for (int i = 0; i < b; i++) 
            cur1 = cur1->right;

        LL2D* cur2 = root;
        for (int i = 0; i < c; i++)
            cur2 = cur2->under;
        for (int i = 0; i < d; i++) 
            cur2 = cur2->right;

        // change left border
        for (int i = 0; i < h; i++) {
            LL2D* left1 = cur1->left;
            LL2D* left2 = cur2->left;
            left1->right = cur2;
            left2->right = cur1;
            cur1->left = left2;
            cur2->left = left1;
            if (i + 1 < h)
                cur1 = cur1->under, cur2 = cur2->under;
        }

        // fix down border
        for (int i = 0; i < w; i++) {
            LL2D* under1 = cur1->under;
            LL2D* under2 = cur2->under;
            under1->above = cur2;
            under2->above = cur1;
            cur1->under = under2;
            cur2->under = under1;
            if (i + 1 < w)
                cur1 = cur1->right, cur2 = cur2->right;
        }

        // fix right border
        for (int i = 0; i < h; i++) {
            LL2D* right1 = cur1->right;
            LL2D* right2 = cur2->right;
            right1->left = cur2;
            right2->left = cur1;
            cur1->right = right2;
            cur2->right = right1;
            if (i + 1 < h)
                cur1 = cur1->above, cur2 = cur2->above;
        }

        //fix upper border
        for (int i = 0; i < w; i++) {
            LL2D* above1 = cur1->above;
            LL2D* above2 = cur2->above;
            above1->under = cur2;
            above2->under = cur1;
            cur1->above = above2;
            cur2->above = above1;
            if (i + 1 < w)
                cur1 = cur1->left, cur2 = cur2->left;
        }
    }

    //print
    print();
}