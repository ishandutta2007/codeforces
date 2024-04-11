n = int(input())

L = [4,7,44,47,74,77,444,447,474,477,744,747,774,777]

for i in range(len(L)):
    if n%L[i]==0:
        print("YES")
        exit(0)
print("NO")
exit(0)