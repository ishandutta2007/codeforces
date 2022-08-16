#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef vector<ppi> vppi;
typedef map<int,int> mii;
typedef map<int,vi> mvi;
typedef map<pii,int> mpi;
typedef priority_queue<ppi,vppi,greater<ppi>> min_heap_ppi;
typedef priority_queue<ppi> max_heap_ppi;
#define For(i,n) for(int i=0;i<n;i++)
#define Rev(i,n) for(int i=n-1;i>=0;i--)
#define tern(a,b,c) (!!(a))*b+(!(a))*c
#define loop(i,a,b) for(int i=a;i!=b;i+=tern(b>a,1,-1))
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define deb2(x,y) cout<<x<<" "<<y<<" "
#define d2(x,y) cout<<x<<" "<<y<<endl
#define d3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define d4(a,b,c,d) deb2(a,b);deb2(c,d);d1("")
#define d5(a,b,c,d,e) deb2(a,b);deb2(c,d);d1(e)
#define d6(a,b,c,d,e,f) deb2(a,b);deb2(c,d);deb2(e,f);d1("")
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(v) v.begin(),v.end()
//#define file cin

const int maxn=6*1000050;
const int MaxN=maxn/10;
//const int maxm=1e16;
int arr[MaxN],prv[MaxN],lpo[3*maxn],rpo[3*maxn],seg[3*maxn],Node=0,root[MaxN];
mii ex;

#define m (s+e)/2

int newParent(int left,int right){
    Node++;
    seg[Node]=seg[left]+seg[right];
    lpo[Node]=left;
    rpo[Node]=right;
    
    return Node;
}

int newLeaf(int val){
    Node++;
    seg[Node]=val;
    lpo[Node]=rpo[Node]=-1;
    return Node;
}

int build(int s,int e){
    if (s==e) return newLeaf(0);
    return(newParent(build(s,m),build(m+1,e)));
}

int update(int node,int s,int e,int l,int val){
    if (l>e || l<s) return node;
    if (s==e) return newLeaf(val);
    if (l<=m) return newParent(update(lpo[node],s,m,l,val),rpo[node]);
    return newParent(lpo[node],update(rpo[node],m+1,e,l,val));
}






int query(int ra,int k,int s,int e){
    if (seg[ra]<=k) return s-1;
    if (s==e) return s;
    if (seg[rpo[ra]]<=k){
        return query(lpo[ra],k-seg[rpo[ra]],s,m);
    }
    return query(rpo[ra],k,m+1,e);
}

int solve(int k,int n){
    int cnt=0;
    int fin=n;
    // d1(k);
    while (fin>0){
        fin=(query(root[fin],k,1,n));
        cnt++;
        // d2(fin,cnt);
    }
    
    return cnt;
}

signed main(){
    fio;
    int n,q,x,y,k,ans=0;
    cin>>n;
    For(i,n) prv[i]=-1;
    For(i,n) {cin>>arr[i];
        if (ex.find(arr[i])!=ex.end()) prv[i]=ex[arr[i]];
        ex[arr[i]]=i;
    }
    root[0]=build(0,n-1);
    For(i,n){
        int temp=root[i];
        if (prv[i]!=-1){
            temp=update(temp,0,n-1,prv[i],0);
        }
        root[i+1]=update(temp,0,n-1,i,1);
        // d2(root[i+1],i+1);
    }
    loop(i,1,n+1){
        d0(solve(i,n));
    }
    
    
}