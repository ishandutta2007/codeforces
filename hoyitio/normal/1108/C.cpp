#include<iostream>

using namespace std;
string dir[10]={"RGB","RBG","BGR","BRG","GRB","GBR"};
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans[10]={0};
    for(int i = 0 ; i < 6 ; i++)
    {
        int t = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(dir[i][t]!=s[j])
            {
                ans[i]++;
            }
            t++;
            t%=3;
        }
    }
    int minn = ans[0],mini = 0;
    for(int i = 0 ; i < 6 ; i++)
    {
        if(minn>ans[i])
        {
            minn = ans[i];
            mini = i;
        }
    }
    int t = 0;
    cout<<minn<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<dir[mini][t];
        t++;
        t%=3;
    }

    return 0;
}