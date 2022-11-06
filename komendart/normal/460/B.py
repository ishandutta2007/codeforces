def main():
    a, b, c = [int(i) for i in input().split()]
    
    result = []
    for S in range(1, 82):
        f = b * S ** a + c
        if 0 < f < 10 ** 9 and sum(int(i) for i in str(f)) == S:
            result.append(str(f))
    
    print(len(result))
    print(' '.join(result))


main()