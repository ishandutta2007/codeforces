#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
const int inf=0x3f3f3f3f;
vector<int>s;
vector<int>v[mn];
int lps[mn*5];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        v[a].push_back((b+n-a)%n);
        v[b].push_back((a+n-b)%n);
    }
    for(i=0;i<n;i++){
        s.push_back(inf);
        sort(v[i].begin(),v[i].end());
        for(int x:v[i])s.push_back(x);
    }
    int l=s.size();
    for(i=0;i<n;i++){
        s.push_back(inf);
        sort(v[i].begin(),v[i].end());
        for(int x:v[i])s.push_back(x);
    }
    s.pop_back();
    for(i=1,j=0;i<s.size();){
        if(s[i]==s[j]){
            lps[i++]=++j;
        }
        else{
            if(j)j=lps[j-1];
            else lps[i++]=0;
        }
    }
    for(i=0;i<s.size();i++)if(lps[i]==l){
        printf("Yes");
        return 0;
    }
    printf("No");
}