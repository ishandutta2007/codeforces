#include <cstdio>
#include <cmath>

using namespace std;

int arr[250];
int N = 250;
void tmain()
{
    double m = 0;
    for(int i=0; i<N; ++i)
    {
        scanf("%d", arr+i);
        m += arr[i];
    }
    m /= N;
    double dev = 0;
    for(int i=0; i<N; ++i)
    {
        dev += (m-arr[i])*(m-arr[i]);
    }
    dev /= N;
    dev = sqrt(dev);
    if(dev < (m/sqrt(3)+sqrt(m))/2)
        puts("poisson");
    else
        puts("uniform");
    return;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--) tmain();
}