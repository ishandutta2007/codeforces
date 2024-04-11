n = int(input())
a = [int(i) for i in  input().split()]

S = sum(a)
final = S // n

result = 0
for i in range(len(a) - 1):
    result += abs(a[i] - final)
    a[i + 1] += a[i] - final

print(result)