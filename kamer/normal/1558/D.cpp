#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

struct TreapNode {
  int key;
  ll priority;
  int incr = 0;
  TreapNode *left, *right;
};


void fix(TreapNode *root, int level) {
    if (level >= 3) return;
    if (root == NULL) return;
    root->key += root->incr;
    if (root->left != NULL) root->left->incr += root->incr;
    if (root->right != NULL) root->right->incr += root->incr;
    fix(root->left, level + 1);
    fix(root->right, level + 1);
    root->incr = 0;
}

void increment(TreapNode *root, int key) {
    
    // if (root) cout << "T " << root->key << endl;
    fix(root, 0);
    // cout << "U " << endl;

    if (root == NULL) return;

    if (key <= root->key) {
        // cout << "V " << endl;
        root->key++;
        // cout << "L " << endl;
        if (root->right != NULL) root->right->incr++;
        // cout << "P " << endl;
        increment(root->left, key);
    } else {
        increment(root->right, key);
    }
}

TreapNode *rightRotate(TreapNode *y) {

  fix(y, 0);

  TreapNode *x = y->left,  *T2 = x->right;
          
  // Perform rotation
  x->right = y;
  y->left = T2;
            
  // Return new root
  return x;
}

TreapNode *leftRotate(TreapNode *x)
{
    fix(x, 0);

    TreapNode *y = x->right, *T2 = y->left;
  
    // Perform rotation
    y->left = x;
    x->right = T2;
  
    // Return new root
    return y;
}

TreapNode* newNode(int key)
{
    TreapNode* temp = new TreapNode();
    temp->key = key;
    temp->priority = rand();
    temp->incr = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

TreapNode* search(TreapNode* root, int key)
{
    fix(root, 0);

    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
  
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
  
    // Key is smaller than root's key
    return search(root->left, key);
}
  
/* Recursive implementation of insertion in Treap */
TreapNode* insert(TreapNode* root, int key)
{
    fix(root, 0);

    // If root is NULL, create a new node and return it
    if (root == NULL)
        return newNode(key);
  
    // If key is smaller than root
    if (key <= root->key)
    {
        // Insert in left subtree
        root->left = insert(root->left, key);
  
        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else  // If key is greater
    {
        // Insert in right subtree
        root->right = insert(root->right, key);
  
        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}



int main(void) {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);

    vector<ll> fact(400000, 1);
    vector<ll> inv_fact(400000, 1);
    vector<ll> inv(400000, 1);
    for (int i = 2; i < 400000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        TreapNode *root = NULL;
        int bad_count = 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (!search(root, y)) {
                // cout << "S " << endl;
                bad_count++;
                root = insert(root, y);
            }
            increment(root, y);
        }

        ll res = (((fact[2 * n - 1 - bad_count] * inv_fact[n]) % MOD) * inv_fact[n - 1 - bad_count]) % MOD;
        cout << res << "\n";
    }
}