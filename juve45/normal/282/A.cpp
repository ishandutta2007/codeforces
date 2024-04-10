#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[7];

int main()
{int k=0;
char s1[]="++";
char s2[]="--";
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
        {
        cin.getline(s, 6);
if(strstr(s, s1)) k++;
else k--;
}
cout<<k;
    
    return 0;

}