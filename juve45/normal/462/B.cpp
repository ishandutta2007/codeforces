#include <bits/stdc++.h>

using namespace std;
int n, k, use[40];
char a[100009];

priority_queue<int>pq;

int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)
    cin>>a[i], use[a[i]-'A']++;

long long ans=0LL;

for(int i='A';i<='Z';i++){
    pq.push(use[i-'A']);
}

while(k>0)
{
    int a=pq.top();
    pq.pop();
    ans+=1LL*min(a,k)*min(a, k);
    k-=a;
}

cout<<ans<<'\n';

    return 0;
}