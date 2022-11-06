#include <iostream>
#include <string>

using namespace std;

struct Node
{
    Node *child[26];
    
    Node()
    {
        for (int i = 0; i < 26; i += 1)
        {
            this->child[i] = 0;
        }
    }
} root;

void insert(string &str)
{
    Node *tmp = &root;
    for (auto c: str)
    {
        int i = c - 'a';
        if (tmp->child[i] == 0)
        {
            tmp->child[i] = new Node();
        }
        tmp = tmp->child[i];
    }
}

bool is_win(Node *current)
{
    for (auto child: current->child)
    {
        if (child != 0 && !is_win(child))
        {
            return true;
        }
    }
    return false;
}

bool is_lose(Node *current)
{
    bool have_children = false;
    for (auto child: current->child)
    {
        if (child != 0)
        {
            have_children = true;
            if (!is_lose(child))
            {
                return true;
            }
        }
    }
    return !have_children;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i += 1)
    {
        string str;
        cin >> str;
        insert(str);
    }
    
    bool win = is_win(&root), lose = is_lose(&root);
    
    if (!win)
    {
        cout << "Second" << endl;
    }
    else if (win && lose)
    {
        cout << "First" << endl;
    }
    else if (k % 2 == 1)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}