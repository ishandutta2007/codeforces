#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=1e6+10;
int lps[mn];
int main(){
    int n;
    scanf("%d",&n);
    n--;
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    for(char&c:s){
        if(c=='N')c='S';
        else if(c=='S')c='N';
        else if(c=='E')c='W';
        else c='E';
    }
    for(int i=1,j=0;i<n;){
        if(s[i]==s[j])lps[i++]=++j;
        else if(j)j=lps[j-1];
        else i++;
    }
    bool gud=1;
    for(int i=0,j=0;i<=n;){
        if(i==n){
            if(j)gud=0;
            break;
        }
        if(t[i]==s[j])i++,j++;
        else if(j)j=lps[j-1];
        else i++;
    }
    if(gud)printf("YES\n");
    else printf("NO\n");
}