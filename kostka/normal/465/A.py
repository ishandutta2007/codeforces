n = int(input())

x = "".join(list(reversed(input())))
k = int(x, 2)

x = str(bin(k))
y = str(bin(k+1))

x = "".join(list(reversed(x)))
y = "".join(list(reversed(y)))

ans = 0
for i in range(len(x)):
    if x[i] != y[i]:
        ans += 1
    if x[i] == 'b':
        break
print(min(n,ans))