#include <iostream>

using namespace std;
int n;
int main()
{
cin>>n;
if(n<=2) cout<<-1<<'\n';
else{while(n)cout<<n<<' ', n--;
}

    return 0;
}