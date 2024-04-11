def main():
    a = [int(i) for i in input().split()]
    result = 0
    while a.count(1) < 4:
        for i in range(6):
            m = i
            l = i - 1 if i != 0 else 5
            r = i + 1 if i != 5 else 0
            if a[l] > 1 and a[r] > 1:
                result += 2 * a[m] + 1
                a[m] += 1
                a[l] -= 1
                a[r] -= 1
    result += 4 * max(a) + 2
    print(result)
    
main()