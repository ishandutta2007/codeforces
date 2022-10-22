#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3510;
int a[mn],v[mn];
set<int> ex[26];
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)ex[s[i]-'a'].insert(i);
    for(int i=0;i<26;i++)ex[i].insert(0x3f3f3f3f);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        bool ans=0;
        if(l==r)ans=1;
        if(s[l]!=s[r])ans=1;
        int num=0;
        for(int i=0;i<26;i++){
            if(*ex[i].lower_bound(l)<=r)num++;
        }
        if(num>=3)ans=1;
        if(ans)printf("Yes\n");
        else printf("No\n");
    }
}