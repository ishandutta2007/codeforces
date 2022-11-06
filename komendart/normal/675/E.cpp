#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define NMAX 100005
#define ll long long
#define maxi(a,b)  (a.first>b.first)?a:b


int arr[NMAX];
int n;
ll dp[NMAX];
int  L[NMAX*4], R[NMAX*4];
int NODES=0;
pair<int, int>  TREE[NMAX*4];
void build(int start, int end, int node)    {
    if(start==end)  {
        TREE[node].first=arr[start];
        TREE[node].second=start;
    }
    else {
        int mid=(start+end)/2;
        L[node]=NODES++;
        R[node]=NODES++;
        build(start, mid, L[node]);
        build(mid+1, end, R[node]);
//        TREE[node].first=max(TREE[L[node]], TREE[R[node]]);
        if(TREE[L[node]].first>TREE[R[node]].first) {
            TREE[node].first=TREE[L[node]].first;
            TREE[node].second=TREE[L[node]].second;
        }
        else {
            TREE[node].first=TREE[R[node]].first;
            TREE[node].second=TREE[R[node]].second;
        }
    }
}


pair<int , int> query(int start, int end, int a, int b,  int node)   {
    int mid=(start+end)/2;
    if(start>=a && end<=b)
        return TREE[node];
    else if(start>b || end<a)
        return make_pair(0, 0);
    else
        return max(query(start, mid, a, b, L[node]), query(mid+1, end, a, b, R[node]));
}



int main() {
//    ios_base::sync_with_stdio(0);
//    int n;
//    cin>>n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&arr[i]);
    ll s=0;
    pair<int, int> f;

    int rt=NODES++, st=1, en=n-1;
    build(st,en, rt);
    
    for(int x=n;x>=1;x--)   {
        if(x==n)
            dp[x]=0;
        else    {
            f=query(st, en, x, arr[x], rt);
            dp[x]=n-arr[x]+f.second-x+dp[f.second];
        }
        s+=dp[x];
    }
    
    cout<<s+n-1<<endl;
    return 0;
}