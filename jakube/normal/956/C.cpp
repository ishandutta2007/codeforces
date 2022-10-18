#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int marks = 0;
    vector<bool> new_mark(n, false);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    long long under = 0;

    for (int i = 0; i < n; i++) {
        int above = v[i];
        int atleast = above + 1;

        if (atleast <= marks) {
            // nothing
            // under += marks - atleast;
        } else {
            // add more marks
            long long additional = atleast - marks;

            int cur = i;
            for (int j = 0; j < additional; j++) {
                while (p[cur] != cur)
                    cur = p[cur];
                p[cur] = cur-1;
                new_mark[cur] = true;
            }
            p[i] = cur - 1;

            // under += additional * (additional - 1) / 2;
            marks = atleast;
        }
    }

    marks = 0;
    for (int i = 0; i < n; i++) {
         if (new_mark[i])
             marks++;
         int above = v[i];
         under += marks - above - 1;
    }
    cout << under << endl;

}