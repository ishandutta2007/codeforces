#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int k,n1,n2,n3,t1,t2,t3;
multiset<int> m1,m2,m3;
inline int Max(int x,int y,int z) {
    return (max(x,max(y,z)));
}
void process(void) {
    cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
    REP(zz,n1) m1.insert(0);
    REP(zz,n2) m2.insert(0);
    REP(zz,n3) m3.insert(0);
    int s;
    REP(zz,k) {
        assert(m1.size()==n1);
        assert(m2.size()==n2);
        assert(m3.size()==n3);
        //FORE(it,m1) printf("%d ",*it); printf("\n");
        //FORE(it,m2) printf("%d ",*it); printf("\n");
        //FORE(it,m3) printf("%d ",*it); printf("\n");
        s=Max(*m1.begin(),*m2.begin()-t1,*m3.begin()-t1-t2);
        //printf("STEP %d %d\n",zz,s);
        __typeof(m1.begin()) i1=m1.upper_bound(s); assert(i1!=m1.begin()); i1--;
        m1.erase(i1);
        m1.insert(s+t1);
        __typeof(m2.begin()) i2=m2.upper_bound(s+t1); assert(i2!=m2.begin()); i2--;
        m2.erase(i2);
        m2.insert(s+t1+t2);
        __typeof(m3.begin()) i3=m3.upper_bound(s+t1+t2); assert(i3!=m3.begin()); i3--;
        m3.erase(i3);
        m3.insert(s+t1+t2+t3);
    }
    cout<<s+t1+t2+t3;
}
int main(void) {
    process();
    return 0;
}