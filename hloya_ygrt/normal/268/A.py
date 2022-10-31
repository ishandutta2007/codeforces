a = []
b = []
n = int(input())
for i in range(n):
    s = input().split()
    a.append(int(s[0]))
    b.append(int(s[1]))
ans = int(0)
for i in range(n):
    for j in range(n):
        if i != j and b[i] == a[j]:
            ans = ans + 1;
print(ans)