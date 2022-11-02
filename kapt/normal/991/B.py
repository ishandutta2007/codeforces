n = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse = True)
x = sum(arr)
ans = 0
while x < 4.5 * n:
    x += (5 - arr[-1])
    arr.pop()
    ans += 1
print(ans)