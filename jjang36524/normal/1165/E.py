N = int(input())
arr = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

arr2.sort()

for i in range(N):
    arr[i] *= (i+1)
    arr[i] *= (N-i)


arr.sort()
arr = arr[::-1]

res = 0

for i in range(N):
    res += arr[i] * arr2[i]
    res %= 998244353;

print(res)