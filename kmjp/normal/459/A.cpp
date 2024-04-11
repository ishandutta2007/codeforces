#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int X1,Y1,X2,Y2;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>X1>>Y1>>X2>>Y2;
    if(X1!=X2 && Y1!=Y2 && abs(X1-X2)==abs(Y1-Y2)) {
        _P("%d %d %d %d\n",X1,Y2,X2,Y1);
    }
    else if(X1==X2 && Y1!=Y2) {
        _P("%d %d %d %d\n",X1+abs(Y1-Y2),Y1,X1+abs(Y1-Y2),Y2);
    }
    else if(X1!=X2 && Y1==Y2) {
        _P("%d %d %d %d\n",X1,Y1+abs(X1-X2),X2,Y2+abs(X1-X2));
    }
    else _P("-1\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}