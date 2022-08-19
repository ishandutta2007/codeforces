
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
void solve_single_test(int test_id=1){
    int n,m,a,b;
    io>>n>>m>>a>>b;
    vector<vector<int>> h(n,vector<int>(m));
    int g,x,y,z;
    io>>g>>x>>y>>z;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            h[i][j]=g;
            g=(1ll*g*x+y)%z;
        }
    }
    vector<vector<int>> mr(n,vector<int>(m-b+1));
    for(int i=0;i<n;++i){
        deque<int> que;
        for(int j=0;j<m;++j){
            while(!que.empty()&&que.front()<=j-b){
                que.pop_front();
            }
            while(!que.empty()&&h[i][que.back()]>=h[i][j]){
                que.pop_back();
            }
            que.push_back(j);
            if(j>=b-1){
                mr[i][j-b+1]=h[i][que.front()];
            }
        }
    }
    LL ans=0;
    for(int i=0;i<=m-b;++i){
        deque<int> que;
        for(int j=0;j<n;++j){
            while(!que.empty()&&que.front()<=j-a){
                que.pop_front();
            }
            while(!que.empty()&&mr[que.back()][i]>=mr[j][i]){
                que.pop_back();
            }
            que.push_back(j);
            if(j>=a-1){
                ans+=mr[que.front()][i];
            }
        }
    }
    io<<ans<<'\n';
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