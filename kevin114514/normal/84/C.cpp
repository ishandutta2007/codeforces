#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
void die(string S){puts(S.c_str());exit(0);}
int n;
int x[10010],r[10010];
int id[10010];
int m;
int f[10010];
int res;
bool Less(const int &a,const int &b)
{
	return x[a]<x[b];
}
void Search(int lw,int up,int tx,int ty,int ind)
{
    if(lw>up)
		return;
    int mid=(lw+up)/2;
    if(sqr(tx-x[id[mid]])+sqr(ty)<=sqr(r[id[mid]])&&f[id[mid]]==-1)
	{
        res++;
        f[id[mid]]=ind;
    }
    if(tx<x[id[mid]])
		Search(lw,mid-1,tx,ty,ind);
    if(tx>x[id[mid]])
		Search(mid+1,up,tx,ty,ind);
} 
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
	{
        cin>>x[i]>>r[i];
        id[i]=i;
    }
    sort(id,id+n,Less);
    fill(f,f+n,-1);
    cin>>m;
    for(int i=1;i<=m;i++)
	{
        int tx,ty;
		cin>>tx>>ty;
        Search(0,n-1,tx,ty,i);  
    }
    cout<<res<<endl;
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
    return 0;
}