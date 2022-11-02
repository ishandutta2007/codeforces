n = int(input())
s = input()
arr = []
for i in range(n):
    arr.append(s[i])
for i in range(1, n + 1):
    if n % i == 0:
        arr = list(reversed(arr[:i])) + arr[i:]
print(*arr, sep='')