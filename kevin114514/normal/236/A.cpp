#include<bits/stdc++.h>
using namespace std;
int used[26];
int main()
{
    string S;
    cin>>S;
    int cnt=0;
    for(int i=0;i<S.length();i++)
        if(!used[S[i]-'a'])
        {
            used[S[i]-'a']=true;
            cnt++;
        }
    if(cnt%2)
        puts("IGNORE HIM!");
    else    puts("CHAT WITH HER!");
    return 0;
}