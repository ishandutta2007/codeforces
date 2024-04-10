#include <bits/stdc++.h>
#define maxn 101
using namespace std;

string s;
map<int,char> m;
int len,ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);

    cin>>s;
    len=s.size();
    char a = 'a';

    for(int i=0; i<len; i++){
        if(s[i]<=a){
            m[i]=a;
            a++;
            ans++;
        }
    }

    if(ans<26){ cout<<-1<<'\n'; return 0; }

    int cont =0;
    for(int i=0; i<len; i++){
        if(m[i]>='a'&&m[i]<='z'&&cont<=26){
            cout<<m[i];
            cont++;
        }
        else cout<<s[i];
    }


    return 0;
}