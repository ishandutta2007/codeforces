#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-6;
const long double PI=3.1415926535897932384l;
template<typename T> struct point
{
    T x,y;
    bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    point operator+(const point &a) const {return {x+a.x,y+a.y};}
    point operator-(const point &a) const {return {x-a.x,y-a.y};}
    point operator-() const {return {-x,-y};}
    point operator*(const T k) const {return {k*x,k*y};}
    point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const point &a) const {return x*a.x+y*a.y;} //Dot
    T operator^(const point &a) const {return x*a.y-y*a.x;} //Cross
    bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool is_par(const point &a) const {return abs((*this)^a)<=eps;}
    bool is_ver(const point &a) const {return abs((*this)*a)<=eps;}
    int toleft(const point &a) const {auto t=(*this)^a; return (t>eps)-(t<-eps);}
    //<0=0>0
    T len2() const {return (*this)*(*this);}
    T dis2(const point &a) const {return (a-(*this)).len2();}
    double len() const {return sqrt(len2());}
    double dis(const point &a) const {return (a-(*this)).len();}
    double ang(const point &a) const {return acos(((*this)*a)/(this->len()*a.len()));}
    point rot(const double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}
};
template<typename T> struct line
{
    point<T> p,v; //p+tv
    bool operator==(const line &a) const {return (v.is_par(a.v) && v.is_par(p-a.p));}
    bool is_par(const line &a) const {return (v.is_par(a.v) && !v.is_par(p-a.p));}
    bool is_ver(const line &a) const {return v.is_ver(a.v);}
    bool is_on(const point<T> &a) const {return v.is_par(a-p);}
    int toleft(const point<T> &a) const {return v.toleft(a-p);}
    point<T> inter(const line &a) const {return p+v*((a.v^(p-a.p))/(v^a.v));}//
    double dis(const point<T> &a) const {return abs(v^(a-p))/v.len();}
    point<T> proj(const point<T> &a) const {return p+v*((v*(a-p))/(v*v));}//
    // bool operator<(const line &a) const
    // {
    //     if (abs(v^a.v)<=eps && v*a.v>=-eps) return toleft(a.p)==-1;
    //     return argcmp(v,a.v);
    // }
};
template<typename T> struct polygon
{
    vector<point<T>> p;
    inline size_t nxt(const size_t i) const {return i==p.size()-1?0:i+1;}
    inline size_t pre(const size_t i) const {return i==0?p.size()-1:i-1;}
    pair<bool,int> winding(const point<T> &a) const
    {//winding=0
        int cnt=0;
        for (size_t i=0;i<p.size();i++)
        {
            point<T> u=p[i],v=p[nxt(i)];
            if (abs((a-u)^(a-v))<=eps && (a-u)*(a-v)<=eps) return {true,0};
            if (abs(u.y-v.y)<=eps) continue;
            line<T> uv={u,v-u};
            if (u.y<v.y-eps && uv.toleft(a)<=0) continue;
            if (u.y>v.y+eps && uv.toleft(a)>=0) continue;
            if (u.y<a.y-eps && v.y>=a.y-eps) cnt++;
            if (u.y>=a.y-eps && v.y<a.y-eps) cnt--;
        }
        return {false,cnt};
    }
    T mxseg()
    {//
        T ans=0;
        int n=p.size();
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
            {
                vector<point<T>>vc;
                vc.push_back(p[i]);
                vc.push_back(p[j]);
                for(int k=0;k<n;++k)
                {
                    int h=nxt(k);
                    line<T> x={p[i],p[j]-p[i]},y={p[k],p[h]-p[k]};
                    if(x.toleft(p[k])*x.toleft(p[h])>0) continue;
                    if(x.toleft(p[k])==0&&x.toleft(p[h])==0)//
                    {
                        vc.push_back(p[h]);
                        vc.push_back(p[k]);
                        continue;
                    }
                    auto z=x.inter(y);//
                    vc.push_back(z);
                }
                function<bool(point<T>,point<T>)>cmp=[&](point<T>x,point<T>y)
                {
                    if(abs(x.x-y.x)<eps) return x.y<y.y;
                    return x.x<y.x;
                };
                sort(vc.begin(),vc.end(),cmp);
                bool flag=true;
                for(int i=0;i+1<int(vc.size());++i)
                {
                    if((vc[i]-vc.back()).len()<=ans) break;//
                    int j=i;
                    while(j+1<int(vc.size()))
                    {
                        point<T> x=(vc[j]+vc[j+1])/2;
                        auto ret=this->winding(x);
                        if(!ret.first&&ret.second==0) break;
                        //
                        ++j;
                    }
                    ans=max(ans,(vc[i]-vc[j]).len());
                    i=j;
                }
            }
        return ans;
    }
    double circ() const
    {
        double sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i].dis(p[nxt(i)]);
        return sum;
    }
    T area2() const
    {
        T sum=0;
        for (size_t i=0;i<p.size();i++) sum+=p[i]^p[nxt(i)];
        return abs(sum);
    }
};
template<typename T> struct segment
{
    point<T> a,b;
 
    int is_on(const point<T> &p) const
    {
        if (p==a || p==b) return -1;
        return (p-a).toleft(p-b)==0 && (p-a)*(p-b)<-eps;
    }
 
    int is_inter(const line<T> &l) const
    {
        if (l.toleft(a)==0 || l.toleft(b)==0) return -1;
        return l.toleft(a)!=l.toleft(b);
    }
     
    //int is_inter(const segment<T> &s) const
};
template<typename T> struct convex: polygon<T>
{
    template<typename F> void rotcaliper(const F &func) const
    {
        const auto &p=this->p;
        const auto area=[](const point<T> &u,const point<T> &v,const point<T> &w){return abs((w-u)^(w-v));};
        for (size_t i=0,j=1;i<p.size();i++)
        {
            const auto nxti=this->nxt(i);
            func(p[i],p[nxti],p[j]);
            while (area(p[this->nxt(j)],p[i],p[nxti])>=area(p[j],p[i],p[nxti]))
            {
                j=this->nxt(j);
                func(p[i],p[nxti],p[j]);
            }
        }
    }
 
    T diameter2() const
    {
        const auto &p=this->p;
        if (p.size()==1) return 0;
        if (p.size()==2) return p[0].dis2(p[1]);
        T ans=0;
        auto func=[&](const point<T> &u,const point<T> &v,const point<T> &w){ans=max({ans,w.dis2(u),w.dis2(v)});};
        rotcaliper(func);
        return ans;
    }
 
    vector<T> sum;
 
    void get_sum()
    {
        const auto &p=this->p;
        vector<T> a(p.size());
        for (size_t i=0;i<p.size();i++) a[i]=p[this->pre(i)]^p[i];
        sum.resize(p.size());
        partial_sum(a.begin(),a.end(),sum.begin());
    }
 
    T query_sum(const size_t l,const size_t r) const
    {
        const auto &p=this->p;
        if (l<=r) return sum[r]-sum[l]+(p[r]^p[l]);
        return sum[p.size()-1]-sum[l]+sum[r]+(p[r]^p[l]);
    }
    T query_sum() const {return sum.back();}
 
    int is_in(const point<T> &a) const
    {
        const auto &p=this->p;
        size_t l=1,r=p.size()-2;
        while (l<=r)
        {
            const auto mid=(l+r)>>1;
            const auto t1=(p[mid]-p[0]).toleft(a-p[0]),t2=(p[mid+1]-p[0]).toleft(a-p[0]);
            if (t1>=0 && t2<=0)
            {
                if (mid==1 && segment<T>{p[0],p[mid]}.is_on(a)) return -1;
                if (mid+1==p.size()-1 && segment<T>{p[0],p[mid+1]}.is_on(a)) return -1;
                if (segment<T>{p[mid],p[mid+1]}.is_on(a)) return -1;
                return (p[mid+1]-p[mid]).toleft(a-p[mid])>0;
            }
            if (t1<0) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
 
    template<typename F> size_t extreme(const F &dir) const
    {
        const auto &p=this->p;
        const auto check=[&](const size_t i){return dir(p[i]).toleft(p[this->nxt(i)]-p[i])>=0;};
        const auto dir0=dir(p[0]); const auto check0=check(0);
        if (!check0 && check(p.size()-1)) return 0;
        size_t l=0,r=p.size()-1;
        while (l<r)
        {
            const auto mid=(l+r)>>1;
            auto checkm=check(mid);
            if (checkm==check0)
            {
                const auto t=dir0.toleft(p[mid]-p[0]);
                if ((!check0 && t<=0) || (check0 && t<0)) checkm^=1;
            }
            if (checkm) l=mid+1;
            else r=mid;
        }
        return r;
    }
 
    pair<size_t,size_t> tangent(const point<T> &a) const //!is_in(a)
    {
        const size_t i=extreme([&](const point<T> &u){return u-a;});
        const size_t j=extreme([&](const point<T> &u){return a-u;});
        return {i,j};
    }
};
template<typename T> 
bool argcmp(const point<T> &a,const point<T> &b)
{
    auto quad=[](const point<T> &a)
    {
        if (a.y<-eps) return 1;
        if (a.y>eps) return 4;
        if (a.x<-eps) return 5;
        if (a.x>eps) return 3;
        return 2;
    };
    int qa=quad(a),qb=quad(b);
    if (qa!=qb) return qa<qb;
    auto t=a^b;
    if (abs(t)<=eps) return a*a<b*b-eps;
    return t>eps;
}
template<typename T> 
int RotateAxis(vector<point<T>>&a,int t)
{//t
    int n=a.size();
    sort(a.begin(),a.end(),[&](point<T> a,point<T> b)
    {
        return a.x==b.x?a.y<b.y:a.x<b.x;
    });
    struct node
    {
        point<T>p;
        int x,y;
        bool operator<(const node&o)const
        {
            return argcmp(p,o.p);
        };
    };
    vector<node>b;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
        {
            b.emplace_back();
            b.back().p=a[j]-a[i];
            b.back().x=i;
            b.back().y=j;
        }
    sort(b.begin(),b.end());
    vector<int>id(n),pos(n);
    for(int i=0;i<n;++i) id[i]=pos[i]=i;
    int m=b.size();
    int ans=0;
    for(int i=0;i<m;++i)//
    {
        int x=b[i].x,y=b[i].y;
        if(pos[x]>pos[y]) swap(x,y);
        assert(pos[y]==pos[x]+1);
        //
        //0~pos[x]-1
        //pos[y]+1~n-1
        int l=0,r=pos[x];
        while(l<r)
        {
            int mid=(l+r)>>1;
            line<T>g={a[x],a[y]-a[x]};
            if(g.dis(a[id[mid]])<=t) r=mid;
            else l=mid+1;
        }
        ans=max(ans,pos[y]-r+1);
        l=pos[y];r=n-1;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            line<T>g={a[x],a[y]-a[x]};
            if(g.dis(a[id[mid]])<=t) l=mid;
            else r=mid-1;
        }
        ans=max(ans,l-pos[x]+1);
        swap(pos[x],pos[y]);
        swap(id[pos[x]],id[pos[y]]);
    }
    return ans;
}
template<typename T>
double minConvexDis(vector<point<T>>&a,vector<point<T>>&b)
{
    auto sol=[&](vector<point<T>>&a,vector<point<T>>&b)
    {
        int n=a.size(),m=b.size();
        double ans=1e10;
        for(int i=0,j=0;i<n;++i)
        {
            line<T> l={a[i],a[(i+1)%n]-a[i]};
            auto dis=[&](line<T> l,point<T> x)
            {
                point<T> y=l.proj(x);
                if(fabs((y-l.p).len()+(y-l.p-l.v).len()-l.v.len())<eps)
                    return l.dis(x);
                return min((x-l.p).len(),(x-l.p-l.v).len());
            };
            while(dis(l,b[(j+1)%m])<dis(l,b[j])) j=(j+1)%m;
            while(dis(l,b[(j+m-1)%m])<dis(l,b[j])) j=(j+m-1)%m;
            ans=min(ans,dis(l,b[j]));
        }
        return ans;
    };
    return min(sol(a,b),sol(b,a));
}
using _T=long long;
using Point=point<_T>;
using Line=line<_T>;
using Polygon=polygon<_T>;
using Convex=convex<_T>;
vector<Point> convexhull(vector<Point>p)
{
    vector<Point> st;
    sort(p.begin(),p.end());
    const auto check=[](const vector<Point> &st,const Point &u)
    {
        const auto back1=st.back(),back2=*prev(st.end(),2);
        return (back1-back2).toleft(u-back2)<0;
    };
    for (const Point &u:p)
    {
        while (st.size()>1 && check(st,u)) st.pop_back();
        st.push_back(u);
    }
    size_t k=st.size();
    p.pop_back(); reverse(p.begin(),p.end());
    for (const Point &u:p)
    {
        while (st.size()>k && check(st,u)) st.pop_back();
        st.push_back(u);
    }
    st.pop_back();
    return st;
}
Polygon minRectangle(Polygon &a)
{
    double ans=LONG_LONG_MAX;
    Polygon ansp;
    for (int i=0,j=1,l=-1,r=-1;i<(int)a.p.size();i++)
    {
        while (((a.p[a.nxt(j)]-a.p[i])^(a.p[a.nxt(j)]-a.p[a.nxt(i)]))
        >((a.p[j]-a.p[i])^(a.p[j]-a.p[a.nxt(i)]))) j=a.nxt(j);
        if (l==-1) l=i,r=j;
        Point v(a.p[a.nxt(i)]-a.p[i]);
        v={-v.y,v.x};
        while (v.toleft(a.p[a.nxt(l)]-a.p[l])<=0) l=a.nxt(l);
        while (v.toleft(a.p[a.nxt(r)]-a.p[r])>=0) r=a.nxt(r);
        Line li={a.p[i],a.p[a.nxt(i)]-a.p[i]},lj={a.p[j],a.p[i]-a.p[a.nxt(i)]};
        Line ll={a.p[l],v},lr={a.p[r],v};
        vector<Point> t={li.inter(ll),ll.inter(lj),lj.inter(lr),lr.inter(li)};
        Polygon pl;
        pl.p=t;
        double s=pl.area2();
        if (s<ans) ans=s,ansp=pl;
    }
    return ansp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<Point>a(n);
    map<Point,bool>vis;
    for(int i=0;i<n;++i) cin>>a[i].x>>a[i].y,vis[a[i]]=true;
    int m;cin>>m;
    vector<Point>b(m);
    for(int i=0;i<m;++i) cin>>b[i].x>>b[i].y;
    for(auto x:b) if(vis.count(x)){cout<<"NO\n";return 0;}
    b.insert(b.end(),a.begin(),a.end());
    b=convexhull(b);
    for(auto x:b)
        if(!vis.count(x))
        {
            cout<<"NO\n";
            return 0;
        }
    cout<<"YES\n";
}