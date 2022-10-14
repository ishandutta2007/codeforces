    #include <bits/stdc++.h>

    using namespace std;




    const int mod=1e9+7;
    vector<long long> p;


    int ho,mi,se,ho1,mi1;
    void fix_time()
    {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
        if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
        if(ho<0)ho+=24;if(ho>24)ho-=24;
    }
    unsigned long long my_pow(int x,int y)
    {  unsigned  long long num=1;
        for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
            if(y&1)num=(num*i);
                return num;
    }

    bool prime[1000001],prime2[1000001];
    void sieve(){
    for(int i=2;i<=1000000;i+=2)
    prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i*i<=1000000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
                }
    vector<long long>vv,vv1;int cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
            for(long long i=3;i*i<=x;i+=2)
                    if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
                        if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
    long long gcd(long long a , long long b)
    {
      if(b==0) return a;
               a%=b;
        return gcd(b,a);
    }
    int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003];vector<int>v,vr,v2[100003];long long sum,ans,num;char ch;
                    //vector<pair<int,char>>r1,r2;
    map<char,vector<int> > mp1;
    set<int>myset;//its not muuultiset
    bool yes,lft,rt;
    multiset<string>lfts[100001],rts[100001];
    vector<pair<long long,long long> >v1,tmpv;
    char movx,movy;
    multiset<int>muls;

    int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
    bool hast[200001];
    int prevx,prevy;
    map<int,int>mymp,mymp2;
    vector<int>myst;
    multiset<int>mset; set<int>nset;
    string s,ss;char seq[10001][10001];
    map<char,int>mpt[10001];int nums[11],sums[11];long long s1,s2,e1,e2;
    int tree[1000001],A[1000001];
    void build(int node, int start, int endd,bool orr)
    {
        if(start == endd)
        {
            // Leaf node will have a single element
            tree[node] = A[start];
        }
        else
        {
            int mid = (start + endd) / 2;
            // Recurse on the left child
            build(2*node, start, mid,!orr);
            // Recurse on the right child
            build(2*node+1, mid+1, endd,!orr);
            // Internal node will have the sum of both of its children
            if(orr)tree[node] = tree[2*node] | tree[2*node+1];
            else tree[node] = tree[2*node] ^ tree[2*node+1];
        }
    }
    void update(int node, int start, int endd, int idx, int val,bool orr)
    {
        if(start == endd)
        {
            // Leaf node
            A[idx] = val;
            tree[node] = val;
        }
        else
        {
            int mid = (start + endd) / 2;
            if(start <= idx and idx <= mid)
            {
                // If idx is in the left child, recurse on the left child
                update(2*node, start, mid, idx, val,!orr);
            }
            else
            {
                // if idx is in the right child, recurse on the right child
                update(2*node+1, mid+1, endd, idx, val,!orr);
            }
            // Internal node will have the sum of both of its children
            if(orr)tree[node] = tree[2*node] | tree[2*node+1];
            else tree[node] = tree[2*node] ^ tree[2*node+1];
        }
    }
    int query(int node, int start, int endd, int l, int r,bool orr)
    {
        if(r < start || endd < l)
        {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if(l <= start && endd <= r)
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + endd) / 2;
        int p1 = query(2*node, start, mid, l, r,!orr);
        int p2 = query(2*node+1, mid+1, endd, l, r,!orr);
        if(orr)return (p1 | p2);
        return p1^p2;
    }

    int main()
    {

        ios_base::sync_with_stdio(false);
          cin>>n>>m;
          for(int i=1;i<=n;i++)myset.insert(i);
          for(int i=0;i<m;i++)
          {
              cin>>x>>y>>z;
             auto it= myset.lower_bound(x);
             auto it2= myset.lower_bound(y);if(it2!=myset.end()&&(*it2==y))it2++;
             for(;it!=it2;)
             {
                 if(*it!=z){b[*it]=z;
                 auto tmp=it;
                 it++;
                 myset.erase(tmp);}
                 else it++;
             }
          }
     for(int i=1;i<=n;i++)cout<<b[i]<<" ";


        return 0;
    }