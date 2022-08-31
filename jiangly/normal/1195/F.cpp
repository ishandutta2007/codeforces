// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int INF=1e9;
const LL LLINF=1e18;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T>void reverse(vector<T> &a){
    reverse(a.begin(),a.end());
}
void reverse(string &a){
    reverse(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
template<class T>void unique(vector<T> &a){
    a.resize(unique(a.begin(),a.end())-a.begin());
}
class IO{
private:
static const int BUF_SIZE=1<<22;
char in_buf[BUF_SIZE];
char out_buf[BUF_SIZE];
char *in_p1,*in_p2,*out_p;
char stk[20];
public:
IO():in_p1(in_buf),in_p2(in_buf),out_p(out_buf){}
~IO(){
    fwrite(out_buf,1,out_p-out_buf,stdout);
}
char get(){
    return in_p1==in_p2&&(in_p2=(in_p1=in_buf)+fread(in_buf,1,BUF_SIZE,stdin),in_p1==in_p2)?EOF:*in_p1++;
}
void put(char c){
    *out_p++=c;
    if(out_p==out_buf+BUF_SIZE){
        fwrite(out_buf,1,BUF_SIZE,stdout);
        out_p=out_buf;
    }
}
IO& operator >>(int &x){
    x=0;
    char c=get();
    bool sign=false;
    while(!isdigit(c)){
        sign=(c=='-');
        c=get();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=get();
    }
    if(sign){
        x=-x;
    }
    return *this;
}
IO& operator >>(LL &x){
    x=0;
    char c=get();
    bool sign=false;
    while(!isdigit(c)){
        sign=(c=='-');
        c=get();
    }
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-'0';
        c=get();
    }
    if(sign){
        x=-x;
    }
    return *this;
}
IO& operator <<(int x){
    if(x<0){
        put('-');
        x=-x;
    }
    if(x==0){
        put('0');
    }else{
        int top=0;
        while(x>0){
            stk[top++]=x%10+'0';
            x/=10;
        }
        while(top>0){
            put(stk[--top]);
        }
    }
    return *this;
}
IO& operator <<(LL x){
    if(x<0){
        put('-');
        x=-x;
    }
    if(x==0){
        put('0');
    }else{
        int top=0;
        while(x>0){
            stk[top++]=x%10+'0';
            x/=10;
        }
        while(top>0){
            put(stk[--top]);
        }
    }
    return *this;
}
IO& operator <<(char c){
    put(c);
    return *this;
}
IO& operator <<(const string &s){
    for(char c:s){
        put(c);
    }
    return *this;
}
}io;
class BIT{
private:
int n;
vector<int> a;
public:
BIT(int n):n(n){
    a.resize(n+1);
}
void add(int x,int y){
    while(x<=n){
        a[x]+=y;
        x+=x&-x;
    }
}
int sum(int x){
    int y=0;
    while(x){
        y+=a[x];
        x-=x&-x;
    }
    return y;
}
int rangeSum(int l,int r){
    return sum(r)-sum(l-1);
}
};
void solve_single_test(int test_id=1){
    int n;
    io>>n;
    vector<int> last;
    vector<vector<int>> v(n);
    map<pair<int,int>,int> s;
    for(int i=0;i<n;++i){
        int k;
        io>>k;
        vector<pair<int,int>> p(k);
        for(auto &[x,y]:p){
            io>>x>>y;
        }
        // io<<"polygon "<<i+1<<":\n";
        for(int j=0;j<k;++j){
            int x=p[(j+1)%k].first-p[j].first;
            int y=p[(j+1)%k].second-p[j].second;
            int g=abs(__gcd(x,y));
            x/=g;
            y/=g;
            if(!s.count({x,y})){
                s.insert({{x,y},s.size()});
                last.push_back(-1);
            }
            int z=s[{x,y}];
            v[i].push_back(last[z]);
            last[z]=i;
            // io<<'\t'<<s[{x,y}]+1<<'\n';
        }
    }
    int q;
    io>>q;
    vector<vector<pair<int,int>>> query(n);
    vector<int> ans(q);
    for(int i=0;i<q;++i){
        int l,r;
        io>>l>>r;
        query[r-1].emplace_back(l,i);
    }
    BIT t(n);
    for(int i=0;i<n;++i){
        for(int x:v[i]){
            if(x!=-1){
                t.add(x+1,-1);
            }
        }
        t.add(i+1,v[i].size());
        for(auto [l,id]:query[i]){
            ans[id]=t.rangeSum(l,i+1);
        }
    }
    for(int x:ans){
        io<<x<<'\n';
    }
}
void solve_multiple_tests(){
    int n_tests;
    io>>n_tests;
    for(int i=1;i<=n_tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}