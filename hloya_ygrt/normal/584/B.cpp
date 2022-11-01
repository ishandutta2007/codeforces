 #include <iostream>


using namespace std;



long long pow ( long long a, long long n ) {
 if ( n == 0 )
  return 1;
 if ( n % 2 == 1 )
  return pow ( a, n - 1 ) * a % 1000000007;
 else {
  long long b = pow ( a, n / 2 );
  return b * b % 1000000007;
 }
}
int main()
{
    int n,s7=1;
    cin>>n;
    long long ans=0,st;

    ans=20*pow(27,n-1);
    n--;
    while ( n-- ){
        ans +=(pow(7,s7 )*20)%1000000007*pow(27,n)%1000000007;
        ans %= 1000000007;
        s7++;
    }
    cout << ans;
    return 0;
}