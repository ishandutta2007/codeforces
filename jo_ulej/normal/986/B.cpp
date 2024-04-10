#include <iostream>
#include <algorithm>

#define SZ 1000008

long long int eax = 0;

int temp[SZ];
int arr[SZ];

void merge(int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = 0;

	while(i <= m && j <= r)
	{
		if(arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			eax += m - i + 1;
		}
	}

	while(i <= m)
		temp[k++] = arr[i++];

	while(j <= r)
		temp[k++] = arr[j++];

	for(int idx = 0; idx < r - l + 1; ++idx)
		arr[l + idx] = temp[idx];
}

void merge_sort(int l, int r)
{
	int n = r - l + 1;

	if(n < 2)
		return;

	if(n == 2)
	{
		if(arr[l] > arr[r])
		{
			std::swap(arr[l], arr[r]);
			++eax;
		}

		return;
	}

	int m = l + n / 2;

	merge_sort(l, m);
	merge_sort(m + 1, r);

	merge(l, m, r);
}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;

	for(int idx = 0; idx < n; ++idx)
		std::cin >> arr[idx];

	merge_sort(0, n - 1);

	std::cout << (eax % 2 == n % 2 ? "Petr" : "Um_nik") << std::endl;

	return 0;
}