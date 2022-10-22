#include<iostream>

using namespace std;
string dir = "RGB";
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1 ; i < n-1 ; i++)
    {
        if(s[i]==s[i-1])
        {
             cnt++;
            for(int j = 0 ; j < 3 ; j++)
            {
                if(dir[j]!=s[i-1]&&dir[j]!=s[i+1])
                {
                    s[i]=dir[j];

                }
            }
        }
    }
    if(s[n-1]==s[n-2])
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(dir[j]!=s[n-2])
            {
                s[n-1]=dir[j];
            }
        }
        cnt++;
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
    return 0;
}