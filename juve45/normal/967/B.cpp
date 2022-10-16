

#include <iostream>
#include <algorithm>
using namespace std;
unsigned int n, A,B,sizes[100001], hole1Flow, S;
void sort (unsigned int sizes[])
{
    int i, j;
    for (i = 2; i<n; i++)
        for (j= i+1; j<=n; j++)
            if (sizes[i] < sizes[j])
                swap(sizes[i],sizes[j]);
}

int partition (unsigned int arr[], int low, int high)
{
    int pos = low + (rand() % (high - low));
    swap(arr[high], arr[pos]);
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(unsigned int arr[], int low, int high)
{
    int ok = 0;
    for(int i = low + 1; i <= high; i++)
        ok |= (arr[low] != arr[i]);
    if(!ok) return;

    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    unsigned int i;
    cin>>n>>A>>B;
    for ( i=1; i<=n; i++)
    {
        cin>>sizes[i];
        S += sizes[i];
    }
    hole1Flow = sizes[1]*A;
    quickSort(sizes,2,n);
    if (hole1Flow / S >= B)
        cout<<0;
    else
    {
        for (i=2;i<=n;i++)
        {
            S -= sizes[i];
            if (hole1Flow / S >= B)
            {
                break;
            }
        }

         cout<<i-1;
    }

    return 0;
}