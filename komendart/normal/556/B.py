def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    d = 0 if a[0] == 0 else n - a[0]
    for i in range(n):
        if i % 2 == 0:
            a[i] = (a[i] + d) % n
        else:
            a[i] = (a[i] - d + n) % n
    if a == list(range(n)):
        print("Yes")
    else:
        print("No")

main()