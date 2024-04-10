#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
const ll mod=998244353;
int a[26],b[26];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=mn;i;i--){
        bool fail=0;
        for(int j=0;j<n;j++){
            if(a[j]%i!=0)fail=1;
        }
        if(fail)continue;
        for(int j=0;j<n;j++)b[j]=a[j]/i;
        int vo=-1;
        for(int j=0;j<n;j++)if(b[j]&1){
            if(vo==-1)vo=j;
            else fail=1;
        }
        if(fail)continue;
        string s;
        for(int j=0;j<n;j++)for(int k=0;k<b[j]/2;k++)s.push_back('a'+j);
        if(vo!=-1)s.push_back('a'+vo);
        for(int j=n-1;j>=0;j--)for(int k=0;k<b[j]/2;k++)s.push_back('a'+j);
        string ans;
        for(int j=0;j<i;j++)ans+=s;
        printf("%d\n%s",i*(vo==-1?2:1),ans.c_str());
        return 0;
    }
    printf("0\n");
    for(int i=0;i<n;i++)for(int j=0;j<a[i];j++)printf("%c",i+'a');
}