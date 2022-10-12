#include <iostream>
#include <string>
using namespace std;

int main()
{
     int n=0;
     int t=0;
     cin>>n;
     int m[4] ={0}; //    1..3 , 4  

     int h=0;
     int temp = 0;
     for(int i=0; i<n; i++)
     {
         cin >> temp;
         if (temp < 4)
            { m[temp]++; }
         else t++; // 4 
     }

     while (m[3]) { //    -  3+1, 3+0
        m[3]--;
        if (m[1]) m[1]--;
        t++;
     }

     while (m[2]) { //    -  2+2, 2+1, 2+1+1, 2+0
        if (m[2] > 1) m[2]-=2;
        else {
          m[2]--;
          if (m[1] > 1) m[1]-=2;
          else if (m[1]) m[1]--;
        }
        t++;
     }

    while (m[1]) { //    -  1+1+1+1, 1+1+1, 1+1, 1+0
        if (m[1] > 3) m[1]-=4;
        else if (m[1] >2)  m[1]-=3;
        else if (m[1] >1)  m[1]-=2;
        else if (m[1])  m[1]-=1;
        t++;
    }
     cout << t;
}