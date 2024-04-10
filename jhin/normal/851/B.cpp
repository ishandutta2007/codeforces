#include <iostream>

using namespace std;
double  n,k,t,ax,ay,bx,by,cx,cy,ab,bc,ac;
int main()
{
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if((ay-by)*(ax-cx)==(ay-cy)*(ax-bx))return cout<<"No",0;
    ab=(ay-by)*(ay-by)+(bx-ax)*(bx-ax);
    bc=(cy-by)*(cy-by)+(cx-bx)*(cx-bx);

    if(ab==bc)cout<<"Yes";
        else cout<<"No";


    return 0;
}