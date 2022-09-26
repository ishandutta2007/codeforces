#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef unsigned long long ll;
#define int ll

using namespace std;
const int nmax=5e5+100;
int pow2[100];

int ft(int n){
    int c=0;
    int p2=1;
    while (true){
        if (n<=p2)
            break;
        n-=p2;
        c+=2;
        p2*=4;
    }
    return pow2[c]+n-1;
}

int f(int x)
{
    if (x==0) return 0;
    if (x==1) return 2;
    if (x==2) return 3;
    if (x==3) return 1;
}

int st(int n){
    int c=0;
    int p2=1;
    while (true){
        if (n<=p2)
            break;
        n-=p2;
        c+=2;
        p2*=4;
    }
    int ans=pow2[c+1];
    c=0;
    n--;
    while (n>0){
        ans+=f(n%4)*pow2[c];
        n/=4;
        c+=2;
    }
    return ans;
}

int td(int n){
    return (ft(n)^st(n));
}

main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    pow2[0]=1;
    for (int i=1; i<100; i++)
        pow2[i]=2*pow2[i-1];



//    set<int> s;
//    for (int i=1; i<=10000; i++){
//        int a, b;
//        for (a=1; ;a++)
//            if (s.count(a)==0)
//                break;
//        for (b=a+1; ; b++)
//            if (s.count(b)==0)
//            if (s.count(a^b)==0)
//                break;
//        cout<<a<<" "<<b<<" "<<(a^b)<<"\n";
//        cout<<ft(i)<<" "<<st(i)<<" "<<td(i)<<"\n";
//
//if ((a!=ft(i)) or (b!=st(i)) or ((a^b)!=td(i)))
//    while (true) cout<<"=(\n";
////        if (i%4==2)
////            cout<<b<<"\n";
//        s.insert(a);
//        s.insert(b);
//        s.insert(a^b);
//    }



    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        if (n%3==1)
            cout<<ft(n/3+1)<<"\n";
        if (n%3==2)
            cout<<st(n/3+1)<<"\n";
        if (n%3==0)
            cout<<td(n/3)<<"\n";
    }

    return 0;
}