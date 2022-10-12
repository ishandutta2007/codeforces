#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;

    int answer=0;
    a = 'a'+a;


    int s=a.size();

    int current = 1; //a
    int delta =0;
    for(int i=1; i<s; i++)
    {
        delta = a[i]-a[i-1];
        if(delta<0)
        {
            delta=0-delta;
        }
        if(delta>13)
        {
            delta=26-delta;
        }
  //      cout << delta;
  //      cout << " ";
        answer += delta;
    }
   //     cout << " = ";
       cout << answer;
 }