#include <iostream>
#include <string>
using namespace std;

int r[26];

int main()
{
    int n;
    string s;
    cin>>n>>s;
    for (int i = 0; i < n; i++)
        r[s[i]-'a']++;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < r[i]; j++)
            cout<<(char)(i+'a');
    cout<<'\n';
    return 0;
}