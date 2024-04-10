input()
a = list(map(int, input().split()))[::-1]
b = list(map(int, input().split()))[::-1]
ans = 0
while a and b:
    if a.pop() <= b[-1]:
        b.pop()
        ans += 1
print(ans)