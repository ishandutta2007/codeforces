#include<iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 1;
    int ans = 1;
    int l = 0;
    int start = l;
    for(int i = 1 ; i <= s.length()*2-2 ; i++)
    {
        if(start == i%s.length())
        {
            break;
        }
        if(s[i%s.length()]!=s[l])
        {
            cnt++;
            ans = max(ans,cnt);
        }
        else{
            cnt = 1;
            start = i%s.length();
        }
        l = i%s.length();
    }
    cout<<ans;
    return 0;
}