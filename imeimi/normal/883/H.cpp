#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) x.begin(),x.end()
#define dprint printf
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const ll mod = 1e9+7;

int cnt[300], tcnt[300];
int n, nodd;
unordered_set<char> us;
vector<char> vs, ovs;
vector<list<char>> V;
void init(){
    scanf("%d\n",&n);
    char tmp;
    for(int i=0;i<n;i++){
        scanf("%c",&tmp);
        //dprint("input : %d(%c)\n",tmp,tmp);
        ++cnt[tmp];
        us.insert(tmp);
    }
    for(char x : us){
        if(cnt[x]&1){
            ++nodd;
        }
        vs.push_back(x);
    }
    for(char &t : vs)
    {
        //dprint("%c : %d\n",t,cnt[t]);
    }
}

bool pal_cut1(int ps){ //ps : odd
    //dprint("ps = %d\n",ps);
    int cps = n/ps;
    if( nodd > cps) return false;
    V = vector<list<char>>(cps,list<char>());
    //dprint("size = %d\n",V.size());
    copy(cnt,cnt+300,tcnt);
    int itmp = 0;
    for(char &r : vs){
        if(tcnt[r]&1){
            //dprint("tcnt ( %c ) = %d\n",r,tcnt[r]);
            V[itmp].push_back(r);
            --tcnt[r];
            ++itmp;
        }
    }
    assert(itmp==nodd);
    //dprint("itmp = %d\n",itmp);
    for(char &r : vs){
        for(;(itmp<cps) && tcnt[r];tcnt[r]-=2){
            V[itmp].push_back(r);
            V[itmp+1].push_back(r);
            itmp+=2;
        }
    }
    //dprint("AYAY");
    itmp = 0;
    for(int iv=0;iv<(int)vs.size();){
        for(;itmp<cps;){
            //dprint("itmp = %d iv = %c, tcnt[%c]=%d, size(%d)=%d\n",itmp,vs[iv],vs[iv],tcnt[vs[iv]],itmp,V[itmp].size());
            while(iv<vs.size() && tcnt[vs[iv]]==0) ++iv;
            while(itmp<cps && V[itmp].size()==ps) ++itmp;
            if(iv==vs.size() || itmp == cps) return true;
            V[itmp].push_front(vs[iv]);
            V[itmp].push_back( vs[iv]);
            tcnt[vs[iv]]-=2;
        }
    }
    return true;
}

bool pal_cut2(int ps){ //ps : even
    //dprint("ps = %d\n",ps);
    if(nodd) return false;
    int itmp = 0, cps = n/ps;
    V = vector<list<char>>(cps,list<char>());
    //dprint("size = %d\n",V.size());
    copy(cnt,cnt+300,tcnt);
    for(int iv=0;iv<(int)vs.size();){
        for(;itmp<cps;){
            //dprint("itmp = %d iv = %d\n",itmp,iv);
            if(tcnt[vs[iv]]==0) ++iv;
            if(V[itmp].size()==ps) ++itmp;
            if(itmp == cps) return true;
            V[itmp].push_front(vs[iv]);
            V[itmp].push_back( vs[iv]);
            tcnt[vs[iv]]-=2;
        }
    }
    return true;
}
void output(){
    int tot = 0;
    for(auto &x : V){
        assert(x.size()*V.size() == n);
        tot += x.size();
    }
    assert(tot==n);
    printf("%d\n",V.size());
    for(auto &x : V){
        for(char &c : x){
            printf("%c",c);
        }
        printf(" ");
    }
    exit(0);
}
int main(){
    init();
    bool ret = false;
    //dprint("nodd = %d\n",nodd);
    if(n&1){
        for(int i=n;i;i-=2){
            if(n%i==0) ret = pal_cut1(i);
            if(ret) output();
        }
    }else{
        for(int i=n;i;--i){
            //if(i==2) break;
            if(n%i==0) ret = (i&1?pal_cut1(i):pal_cut2(i));
            if(ret) output();
        }
    }
    printf("%d\n",n);
    for(char &r : vs){
        for(;cnt[r]--;) printf("%c ",r);
    }
}