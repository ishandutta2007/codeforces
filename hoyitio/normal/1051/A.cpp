#include<iostream>

using namespace std;

bool isNum(char c)
{
    return (c>='0'&&c<='9');
}
bool isa(char c)
{
    return (c>='a'&&c<='z');
}
bool isA(char c)
{
    return (c>='A'&&c<='Z');
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int cnt[5]={0};
        string s;
        cin >> s;
        for(int i = 0 ;i < s.length() ; i++)
        {
             if(isNum(s[i]))
             {
                 cnt[0]++;
             }
             else if(isa(s[i]))
             {
                 cnt[1]++;
             }
             else if(isA(s[i]))
             {
                 cnt[2]++;
             }
        }
        if(!cnt[0])//
        {
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(isa(s[i])&&cnt[1]>=2)
                {
                    s[i] = '1';
                    cnt[0]++;
                    cnt[1]--;
                    break;
                }
                if(isA(s[i])&&cnt[2]>=2)
                {
                    s[i] = '1';
                    cnt[0]++;
                    cnt[2]--;
                    break;
                }
            }
        }
        if(!cnt[1])//
        {
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(isNum(s[i])&&cnt[0]>=2)
                {
                    s[i] = 'a';
                    cnt[1]++;
                    cnt[0]--;
                    break;
                }
                if(isA(s[i])&&cnt[2]>=2)
                {
                    s[i] = 'a';
                    cnt[1]++;
                    cnt[2]--;
                    break;
                }
            }
        }
        if(!cnt[2])//
        {
            for(int i = 0 ; i < s.length() ; i++)
            {
                if(isNum(s[i])&&cnt[0]>=2)
                {
                    s[i] = 'A';
                    cnt[2]++;
                    cnt[0]--;
                    break;
                }
                if(isa(s[i])&&cnt[1]>=2)
                {
                    s[i] = 'A';
                    cnt[2]++;
                    cnt[1]--;
                    break;
                }
            }
        }
        cout<<s<<endl;
    }

    return 0;
}