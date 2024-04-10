n = int(input())
prev = [int(x) for x in input().split()]
x = n;
ans = [x];
while x > 1:
    x = prev[x - 2]
    ans.append(x)
ans.reverse()
print(*ans)