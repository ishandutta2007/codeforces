#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=19;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    long double a,b,c;
    cin>>a>>b>>c;
    if(a==0){
        if(b==0){
            if(c==0){
                printf("-1");
            }
            else{
                printf("0");
            }
        }
        else{
            printf("1\n%.20Lf",-c/b);
        }
    }
    else{
        if(a<0)a=-a,b=-b,c=-c;
        double disc=b*b-4*a*c;
        if(disc<0)printf("0");
        else if(disc==0)printf("1\n%.20Lf",-b/(2*a));
        else printf("2\n%.20Lf\n%.20Lf",(-b-sqrt(disc))/(2*a),(-b+sqrt(disc))/(2*a));
    }
}