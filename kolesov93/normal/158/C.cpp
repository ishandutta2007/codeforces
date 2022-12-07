#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


struct node {
    string path;
    map<string, int> edge;
    int ancestor;
    
    node(string apath, int aancestor) : path(apath), ancestor(aancestor) {}
};
vector<node> tree;

int q;

vector<string> split(string s) {
    vector<string> result;
    string current;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '/') {
            if (current.size() > 0) result.push_back(current);
            current = "";
        } else {
            current += s[i];
        }
    if (current.size() > 0) result.push_back(current);
    return result;
}

int main() {
    cin >> q;
    
    tree.push_back(node("/", 0));
    
    int current = 0;
    while (q--) {
        string com;
        cin >> com;
        
        if (com[0] == 'p') {
            cout << tree[current].path;
            if (*(tree[current].path.rbegin()) != '/') cout << '/';
            cout << endl;
            continue;
        } else {
            cin >> com;
            
            if (com[0] == '/') current = 0;
            vector<string> p = split(com);
            
            for (int i = 0; i < p.size(); ++i)
                if (p[i] == "..") {
                    current = tree[current].ancestor;
                } else {
                    map<string, int>::iterator it = tree[current].edge.find(p[i]);
                    if (it == tree[current].edge.end()) {
                        string npath = tree[current].path;
                        if (*npath.rbegin() != '/') npath += '/';
                        npath += p[i];
                        
                        tree.push_back(node(npath, current));
                        tree[current].edge[ p[i] ] = int(tree.size()) - 1;
                    }
                    current = tree[current].edge[ p[i] ];
                }
        }
    }
    
    return 0;
}