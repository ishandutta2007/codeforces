#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
class TreeNode {
public:
    TreeNode(std::vector<int>& numbers, int begin, int end) {
        if (end - begin == 1) {
            value = numbers[begin];
            return;
        }
        
        int mid = (begin + end) / 2;
        left = new TreeNode(numbers, begin, mid);
        right = new TreeNode(numbers, mid, end);
    }
    
    ~TreeNode() {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }
    
    void update(int index, int new_value, int begin, int end) {
        if (index < begin || index >= end) {
            cout << "ERROR update " << index << " " << begin << " " << end << "\n";
        }
        worky_update();
        
        if (end - begin == 1) {
            value = new_value;
            return;
        }

        int mid = (begin + end) / 2;
        if (index < mid) {
            left->update(index, new_value, begin, mid);
        } else {
            right->update(index, new_value, mid, end);
        }
    }
    
    void payoff(int value) {
        worky_update();
        lazy_update = value;
    }
    
    int get_value(int index, int begin, int end) {
        if (index < begin || index >= end) {
            cout << "ERROR get_value " << index << " " << begin << " " << end << "\n";
        }
        worky_update();
        
        if (end - begin == 1) {
            return value;
        }

        int mid = (begin + end) / 2;
        if (index < mid) {
            return left->get_value(index, begin, mid);
        } else {
            return right->get_value(index, mid, end);
        }
    }
 
private:
    void worky_update() {
        if (left != NULL) {
            left->lazy_update = max(left->lazy_update, lazy_update);
        }
        
        if (right != NULL) {
            right->lazy_update = max(right->lazy_update, lazy_update);
        }
        
        if (lazy_update > value) {
            value = lazy_update;
        }
        lazy_update = -1;
    }
 
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    int value = -1;
    int lazy_update = -1;
};
 
int main(void) {
    int n;
    cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
        
    TreeNode *root = new TreeNode(nums, 0, n);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            root->update(p - 1, x, 0, n);
        } else if (type == 2) {
            int p;
            cin >> p;
            root->payoff(p);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int val = root->get_value(i, 0, n);
        std::cout << val << " ";
    }
    
    delete root;
    return 0;
}