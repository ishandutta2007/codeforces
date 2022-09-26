#include <bits/stdc++.h>
using namespace std;

//#define int long long
int pow(int x, int y)
{
    int ans=1;
    for (int i=1; i<=y; i++)
        ans*=x;
    return ans;
}


int ANS;
int a[1000100];
void quickSort(int arr[], int left, int right) {

      int i = left, j = right;

      int tmp;

      int pivot = arr[(left + right) / 2];



      /* partition */

      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;
                if (i!=j)
                  ANS++;

                  i++;

                  j--;

            }

      };



      /* recursion */

      if (left < j)

            quickSort(arr, left, j);

      if (i < right)

            quickSort(arr, i, right);

}

main()
{
    int n;
    cin>>n;
    int x;
    ANS=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    quickSort(a,1,n);
    /*cout<<ANS<<"\n";
    for (int i=1; i<=n; i++)
        cout<<a[i];*/
    if ((ANS-3*n)%2==0)
        cout<<"Petr\n";
    else
        cout<<"Um_nik\n";
    return 0;
}