s = input()
n = int(input())
w = list(map(int, input().split(" ")))
k = max(w)
ans = 0
it = 0
for lit in s:
    it += 1
    ans += w[ord(lit)-ord('a')]*it
for i in range(n):
    it += 1
    ans += k*it
print(ans)