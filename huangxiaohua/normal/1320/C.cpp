#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,s[200500][2],m1,r1,r2,it,res=-2e9;
int a[200500];
set<pair<int,int> >s1;
vector<pair<int,int> >v;
vector<int> v2;
struct sb{
	int x,y,w;
	bool operator<(const sb a)const{return (x==a.x)?y<a.y:x<a.x;}
}s2[200500];

int tree[800500],lazy[800500];
void build(int node=1, int l=1, int r=m)
{
    if(l==r)
    {
        tree[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(node<<1, l, mid);
    build((node<<1)+1, mid+1, r);
    tree[node]=std::max(tree[node<<1], tree[(node<<1)+1]);
}

void pushdown(int node)
{
    if(lazy[node])
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        tree[node<<1]+=lazy[node];
        tree[(node<<1)+1]+=lazy[node];
        lazy[node]=0;
    }
}

int g_L,g_R,g_Add;
void change(int node=1, int l=1, int r=m)
{
    if(g_L<=l && r<=g_R)
    {
        tree[node]+=g_Add; //g_Addg_Add 
        lazy[node]+=g_Add; //lazy 
        return;
    }
    int mid=(l+r)/2;
    int lc=node<<1;
    int rc=(node<<1)+1;
    //g_Add 
    pushdown(node); //lazy 
    if(g_L<=mid)
        change(lc, l, mid);
    if(g_R>mid)
        change(rc, mid+1, r);
    tree[node]=std::max(tree[lc],tree[rc]); // 
}

//g_Lg_R
int query(int node=1, int l=1, int r=m)
{
    if(g_L<=l && r<=g_R)
    {
        return tree[node]; //tree[node]tree[node]tree[node]lazy[node] 
    }
    int mid=(l+r)/2;
    int lc=node<<1;
    int rc=(node<<1)+1;
    pushdown(node); // 

    int ans=0x80000000;
    if(g_L<=mid)
        ans=std::max(ans, query(lc, l, mid));
    if(g_R>mid)
        ans=std::max(ans, query(rc, mid+1, r));
    return ans;
}

int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	for(auto [i,j]:v){
		if(i==s[m1][0]){continue;}
		while(s[m1][1]>=j){m1--;}
		s[++m1][0]=i;s[m1][1]=j;
	}
	for(i=1;i<=m1;i++){
		s1.insert({s[i][0],s[i][1]});
	}
	
	v.clear();it=0;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());m1=0;
	for(auto [i,j]:v){
		a[++it]=-j;
		v2.push_back(i);
		//printf("a%d %d %d\n",it,i,j);
	}
	v2.push_back(1145141919);
	
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&s2[i].x,&s2[i].y,&s2[i].w);
	}
	sort(s2+1,s2+t+1);
	
	it=1;
	s2[t+1].x=1145141919;
	build();
	
	g_L=1;
    g_R=m;
	//printf("a%d\n",query());
	for(auto [i,j]:s1){
		//printf("b%d %d\n",i,j);
		while(s2[it].x<i){
			int it2=upper_bound(v2.begin(),v2.end(),s2[it].y)-v2.begin()+1;
			//printf("%d %d\n",s2[it].y,it2);
			if(it2<=m){
				g_L=it2;
            	g_R=m;
            	g_Add=s2[it].w;
            	change();
			}
            it++;
		}
		//printf("b%d %d %d\n",i,j,it);
		g_L=1;
        g_R=m;
		res=max(res,query()-j);
	}
	printf("%d",res);
}