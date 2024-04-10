#include <iostream>

using namespace std;

int main() {
    
    long long a,b,c,d,br=0;
    cin>>a>>b>>c>>d;
    if(b==a)br++;
    if(c==b || c==a)br++;
    if(d==c || d==b || d==a)br++;
    cout<<br;
    return 0;
}