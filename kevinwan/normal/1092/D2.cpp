#include <bits/stdc++.h>
using namespace std;
int a[200001];
int p[200001],s[200001];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int u(int a,int b){a=f(a),b=f(b);if(a!=b)s[a]+=s[b],p[b]=a;}
int gs(int x){return s[f(x)];}
struct comp{
    bool operator()(int x,int y){return a[x]>a[y];}
};
int main()
{
    int n,i;
    scanf("%d",&n);
    priority_queue<int,vector<int>,comp>pq;
    for(i=0;i<n;i++){
        scanf("%d",a+i);
        pq.push(i);
        p[i]=i;
        s[i]=1;
    }
    while(pq.size()){
        int h=a[pq.top()];
        vector<int>v;
        while(pq.size()&&a[pq.top()]==h){
            v.push_back(pq.top());
            pq.pop();
        }
        for(int x:v){
            if(x>0&&a[x]>=a[x-1])u(x,x-1);
            if(x<n-1&&a[x]>=a[x+1])u(x,x+1);
        }
        for(int x:v){
            if(gs(x)%2&&gs(x)!=n){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}