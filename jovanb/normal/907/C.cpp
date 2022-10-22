#include <bits/stdc++.h>

using namespace std;
char ch[200000];
int jesu[26],nisu[26],ima[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n,k,shok=0,ges=0,broj1,broj2,i,z;
    char ch1;
    for(i=0;i<26;i++)jesu[i]=1;
    cin>>n;
    for(k=1;k<n;k++){
        for(i=0;i<26;i++)ima[i]=0;
        cin>>ch1>>ch;
        z=strlen(ch);
        for(i=0;i<z;i++)ima[ch[i]-97]=1;
        if(ch1=='!'){
            if(ges==1)shok++;
            for(i=0;i<z;i++)if(nisu[ch[i]-97]==0)jesu[ch[i]-97]=1;
            for(i=0;i<26;i++){
                if(ima[i]==0)nisu[i]=1;
            }
        }
        if(ch1=='.'){
            for(i=0;i<z;i++){
                jesu[ch[i]-97]=0;
                nisu[ch[i]-97]=1;
            }
        }
        if(ch1=='?'){
            if(ges==1)shok++;
            nisu[ch[0]-97]=1;
        }
        broj1=0;
        broj2=0;
        for(i=0;i<26;i++){
            broj1+=jesu[i];
            broj2+=nisu[i];
        }
        if(broj1<=1 || broj2>=25)ges=1;
    }
    cin>>ch1>>ch;
    cout<<shok;
    return 0;
}