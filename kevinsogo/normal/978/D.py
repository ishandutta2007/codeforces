n = int(input())
if n == 1:
    ans = 0
else:
    a = list(map(int, input().split()))
    ans = min(
        sum([0, 1, float('inf')][min(2, abs(v + (w - v) * i - x))] for i, x in enumerate(a))
        for v in range(a[0]-1,a[0]+2)
        for w in range(a[1]-1,a[1]+2))
print(ans if ans < float('inf') else -1)