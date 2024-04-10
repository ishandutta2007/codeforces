#include <bits/stdc++.h> 


#define ll long long
#define md 1000000007LL
#define EPS 0.000000000001

using namespace std;

int a[2000000];
int n, w;


bool check(double x) 
{
    if ((double)a[n / 2] < 2.0 * x || (double) n * x * 3.0 / 2.0 > w) 
    {
        return false;
    }

    return true;
}



int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);
    #endif //DEBUG
    
    scanf("%d %d", &n, &w);
    n *= 2;

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
       // a[i] = 100000000;
    }

    sort(a, a + n);

    double l = 0, r = (double)a[0];

    while (r - l > EPS) 
    {
        double mid = (l + r) / 2.0;
//        printf("%.8lf\n", mid);
        if (check(mid)) 
        {
            l = mid;
        } else 
        {
            r = mid;
        }
    }

    printf("%.8lf\n", (double)n * l * 3.0 / 2.0);


    fprintf(stderr, "Execution time = %.4lfsec", (double)clock() / (double)CLOCKS_PER_SEC);    
    return 0;

}