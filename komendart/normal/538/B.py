def main():
    n = [int(i) for i in input()]
    
    number = max(n)
    
    print(number)
    for i in range(number):
        k = []
        for j in n:
            if j > i:
                k.append(1)
            elif k:
                k.append(0)
        print(''.join(str(i) for i in k), end=' ')
    print()

main()