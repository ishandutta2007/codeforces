#include<bits/stdc++.h>
using namespace std;
const int s = 1000000;

int n,use;
bool exist[1000005];

vector<pair<int,int> >canuse;
vector<int>ans;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int cur;
        scanf("%d",&cur);
        exist[cur] = true;
    }
    for(int i=1;i<=s/2;i++) {
        if(exist[i] && exist[s+1-i]) use++;
        else if(exist[i]) ans.push_back(s+1-i);
        else if(exist[s+1-i]) ans.push_back(i);
        else canuse.push_back({i,s+1-i});
    }
    printf("%d\n",n);
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    for(int i=0;i<use;i++) printf("%d %d ",canuse[i].first,canuse[i].second);
}